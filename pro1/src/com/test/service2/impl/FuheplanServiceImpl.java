package com.test.service2.impl;

import com.test.dao2.FuheplanDao;
import com.test.pojo2.Fuheplan2;
import com.test.service2.FuheplanService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * Created by 世康 on 2016/9/19.
 */
@Service(value = "fuheplan2Service")
public class FuheplanServiceImpl implements FuheplanService {

    @Autowired
    private FuheplanDao fuheplan2Dao;

    @Override
    public List<Fuheplan2> getFuheplanAll() {
        return fuheplan2Dao.getFuheplanAll();
    }

    @Override
    public List<Fuheplan2> getFuheplan(int currentPaging, int pageSize) {
        return fuheplan2Dao.getFuheplan(currentPaging, pageSize);
    }

    @Override
    public Fuheplan2 getFuheplanById(String id) {
        return fuheplan2Dao.getFuheplanById(id);
    }

    @Override
    public int getFuheplanCount() {
        return fuheplan2Dao.getFuheplanCount();
    }
}
