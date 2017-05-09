package com.test.dao.impl;

import com.test.dao.FuheplanDao;
import com.test.pojo.Fuheplan;
import org.hibernate.Criteria;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 世康 on 2016/9/19.
 */
@Repository(value = "fuheplanDao")
public class FuheplanDaoImpl implements FuheplanDao {

    @Autowired
    private SessionFactory sessionFactory;

    @SuppressWarnings("unchecked")
    @Override
    public List<Fuheplan> getFuheplanAll() {
        Session session = sessionFactory.getCurrentSession();
        List<Fuheplan> list = new ArrayList<Fuheplan>();
        Criteria criteria = session.createCriteria(Fuheplan.class);
        list = criteria.list();
        if(list!= null && list.size() > 0){
            return list;
        }
        return null;
    }

    @Override
    public List<Fuheplan> getFuheplan(int currentPaging, int pageSize) {
        return null;
    }

    @Override
    public Fuheplan getFuheplanById(String id) {
        return null;
    }

    @Override
    public int getFuheplanCount() {
        List<Fuheplan> list = getFuheplanAll();
        if (list == null) {
            return 0;
        }
        return list.size();
    }
}
